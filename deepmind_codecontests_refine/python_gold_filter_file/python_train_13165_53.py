from sys import stdin, stdout, stderr, setrecursionlimit
setrecursionlimit(100000)

def debug (*e):
    if not __debug__:
        print(*e, file=stderr)

def dd(*vals):
    import inspect, re
    frame = inspect.getframeinfo(inspect.stack()[1][0])
    vs = re.search("dd\((.+)\)", frame.code_context[0]).group(1).split(",")
    if vs:
        debug(",".join("{0} = {1}".format(vs[i], v) for i,v in enumerate(vals)))

def trace(f):
    def traced(*args, **kw):
        debug("calling {} with args {}, {}".format(f.__name__, args, kw))
        return f(*args, **kw)
    return traced
#@trace
#def f(x):

def read():
    return stdin.readline().rstrip()

def readarr(sep=None, maxsplit=-1):
    return read().split(sep, maxsplit)

def readint():
    return int(read())

def readintarr(sep=None, maxsplit=-1):
    return [int(a) for a in readarr(sep, maxsplit)]

#write(1, 2, 3, sep="-", end="!")
def write(*args, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    stdout.write(sep.join(str(a) for a in args) + end)

#writearr([1, 2, 3], sep="-", end="!")
def writearr(arr, sep=' ', end='\n'):
    stdout.write(sep.join(str(a) for a in arr) + end)

n1, n2 = [int(n) for n in read()]

d = {}
d[0] = [8]
d[1] = [9, 8, 7, 4, 3, 0]
d[2] = [8]
d[3] = [9, 8]
d[4] = [9, 8]
d[5] = [9, 8, 6]
d[6] = [8]
d[7] = [9, 8, 3, 0]
d[8] = []
d[9] = [8]

write((len(d[n1])+1)*(len(d[n2])+1))
