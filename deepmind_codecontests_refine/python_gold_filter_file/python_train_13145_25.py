import sys, os, io
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')
import math,datetime,functools,itertools,operator,bisect,fractions,statistics
from collections import deque,defaultdict,OrderedDict,Counter
from fractions import Fraction
from decimal import Decimal
from sys import stdout

  

def main():
    starttime=datetime.datetime.now()
    if(os.path.exists('input.txt')):
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")

    for _ in range(ri()):
        a,b=ria()
        c1,c2,c3,c4,c5,c6=ria()
        
        if a>=0 and b>=0:
            cost1=c6*a+c2*b
            if a>=b:
                # First Sectant
                cost2=c1*b+c6*(a-b)
                cost3=c1*a+c5*(a-b)
            else:
                # Second Sectant
                cost2=c1*b+c3*(b-a)
                cost3=c1*a+c2*(b-a)
        elif a<=0 and b>=0:
            #Third Sectant
            a=-a
            cost1=c3*a+c2*b
            cost2=c4*a+c2*(a+b)
            cost3=c1*b+c3*(a+b)
            
            
        elif a<=0 and b<=0:
            a=-a
            b=-b
            cost1=c3*a+c5*b
            if a>=b:
                # Fourth Sectant
                cost2=c4*b+c3*(a-b)
                cost3=c4*a+c2*(a-b)
            else:
                # Fifth Sectant
                cost2=c4*b+c6*(b-a)
                cost3=c4*a+c5*(b-a)
        elif b<=0 and a>=0:
            #Sixth Sectant
            b=-b
            cost1=c6*a+c5*b
            cost2=c1*a+c5*(a+b)
            cost3=c4*b+c6*(a+b)
        print(min(cost1,cost2,cost3))    
            
        
        
        
        
            
        
                
        
        
        
            
            
        
        
            
        
        

        
        
            
        
        
            
        
                        

        
        
            
     
        
        
            
        
        
                
            
        
        
        
                
            
        

            
             
        
            
        
        
        
                
        
            
        
        
        
        
                
        
        
            
        
        
        
        
                
        
    #<--Solving Area Ends
    endtime=datetime.datetime.now()
    time=(endtime-starttime).total_seconds()*1000
    if(os.path.exists('input.txt')):
        print("Time:",time,"ms")  
    
                
class FastReader(io.IOBase):
    newlines = 0

    def __init__(self, fd, chunk_size=1024 * 8):
        self._fd = fd
        self._chunk_size = chunk_size
        self.buffer = io.BytesIO()

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, self._chunk_size))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self, size=-1):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, self._chunk_size if size == -1 else size))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()


class FastWriter(io.IOBase):

    def __init__(self, fd):
        self._fd = fd
        self.buffer = io.BytesIO()
        self.write = self.buffer.write

    def flush(self):
        os.write(self._fd, self.buffer.getvalue())
        self.buffer.truncate(0), self.buffer.seek(0)


class FastStdin(io.IOBase):
    def __init__(self, fd=0):
        self.buffer = FastReader(fd)
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


class FastStdout(io.IOBase):
    def __init__(self, fd=1):
        self.buffer = FastWriter(fd)
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.flush = self.buffer.flush


if __name__ == '__main__':
    sys.stdin = FastStdin()
    sys.stdout = FastStdout()
    main()
    