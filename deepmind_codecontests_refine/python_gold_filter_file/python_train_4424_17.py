from sys import stdin, stdout

def trace(f):
    def traced(*args, **kw):
        print("calling {} with args {}, {}".format(f.__name__, args, kw))
        return f(*args, **kw)
    return traced

@trace
def f(x):
    print(x)

def read():
    return stdin.readline()[:-1]

def readarr(sep=None, maxsplit=-1):
    return read().split(sep, maxsplit)

def readint():
    return int(read())

def readintarr(sep=None, maxsplit=-1):
    return [int(a) for a in readarr(sep, maxsplit)]

def write(*args, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    stdout.write(sep.join(str(a) for a in args) + end)

def writearr(arr, sep=' ', end='\n'):
    stdout.write(sep.join(str(a) for a in arr) + end)

def solve():
    for i in range(0, L):
        for j in range(i, L+1):
            w = word[:i] + word[j:]
            #print(word[0:i], "-", word[j:])
            if w == "CODEFORCES":
                write("YES")
                return
    write("NO")

word = read()
L = len(word)
cf = set("CODEFORCES")
while word:
    w = "".join(c for c in word if c in cf)
    length = len(w)
    if length < 10:
        word = read()
        write("NO")
        continue
    solve()
    word = read()
