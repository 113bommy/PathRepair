''' CODED WITH LOVE BY SATYAM KUMAR '''

from sys import stdin, stdout
import cProfile, math
from collections import Counter,defaultdict,deque
from bisect import bisect_left,bisect,bisect_right
import itertools
from copy import deepcopy
from fractions import Fraction
import sys, threading
import operator as op
from functools import reduce
sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size
fac_warmup = False
printHeap = str()
memory_constrained = False
P = 10**9+7
import sys

class merge_find:
    def __init__(self,n):
        self.parent = list(range(n))
        self.size = [1]*n
        self.num_sets = n
        self.lista = [[_] for _ in range(n)]
    def find(self,a):
        to_update = []
        while a != self.parent[a]:
            to_update.append(a)
            a = self.parent[a]
        for b in to_update:
            self.parent[b] = a
        return self.parent[a]
    def merge(self,a,b):
        a = self.find(a)
        b = self.find(b)
        if a==b:
            return
        if self.size[a]<self.size[b]:
            a,b = b,a
        self.num_sets -= 1
        self.parent[b] = a
        self.size[a] += self.size[b]
        self.lista[a] += self.lista[b]
    def set_size(self, a):
        return self.size[self.find(a)]
    def __len__(self):
        return self.num_sets

def display(string_to_print):
    stdout.write(str(string_to_print) + "\n")

def primeFactors(n): #n**0.5 complex 
    factors = dict()
    for i in range(2,math.ceil(math.sqrt(n))+1):  
        while n % i== 0: 
            if i in factors:
                factors[i]+=1
            else: factors[i]=1
            n = n // i 
    if n>2:
        factors[n]=1
    return (factors)

def all_factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

def fibonacci_modP(n,MOD):
    if n<2: return 1
    #print (n,MOD)
    return (cached_fn(fibonacci_modP, (n+1)//2, MOD)*cached_fn(fibonacci_modP, n//2, MOD) + cached_fn(fibonacci_modP, (n-1) // 2, MOD)*cached_fn(fibonacci_modP, (n-2) // 2, MOD)) % MOD

def factorial_modP_Wilson(n , p): 
    if (p <= n): 
        return 0
    res = (p - 1) 
    for i in range (n + 1, p): 
        res = (res * cached_fn(InverseEuler,i, p)) % p 
    return res 

def binary(n,digits = 20):
    b = bin(n)[2:]
    b = '0'*(digits-len(b))+b
    return b

def isprime(n):
    """Returns True if n is prime."""
    if n < 4:
        return True
    if n % 2 == 0:
        return False
    if n % 3 == 0:
        return False
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += w
        w = 6 - w
    return True

def generate_primes(n):
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * 2, n+1, p): 
                prime[i] = False
        p += 1
    return prime

factorial_modP = []
def warm_up_fac(MOD):
    global factorial_modP,fac_warmup
    if fac_warmup: return
    factorial_modP= [1 for _ in range(fac_warmup_size+1)]
    for i in range(2,fac_warmup_size):
        factorial_modP[i]= (factorial_modP[i-1]*i) % MOD
    fac_warmup = True

def InverseEuler(n,MOD):
    return pow(n,MOD-2,MOD)

def nCr(n, r, MOD):
    global fac_warmup,factorial_modP
    if not fac_warmup:
        warm_up_fac(MOD)
        fac_warmup = True
    return (factorial_modP[n]*((pow(factorial_modP[r], MOD-2, MOD) * pow(factorial_modP[n-r], MOD-2, MOD)) % MOD)) % MOD

def test_print(*args):
    if testingMode:
        print(args)

def display_list(list1, sep=" "):
    stdout.write(sep.join(map(str, list1)) + "\n")

def display_2D_list(li):
    for i in li:
        print(i)
def prefix_sum(li):
    sm = 0
    res = []
    for i in li:
        sm+=i
        res.append(sm)
    return res

def get_int():
    return int(stdin.readline().strip())

def get_tuple():
    return map(int, stdin.readline().split())

def get_list():
    return list(map(int, stdin.readline().split()))
import heapq,itertools
pq = []                         # list of entries arranged in a heap
entry_finder = {}               # mapping of tasks to entries
REMOVED = '<removed-task>' 
def add_task(task, priority=0):
    'Add a new task or update the priority of an existing task'
    if task in entry_finder:
        remove_task(task)
    count = next(counter)
    entry = [priority, count, task]
    entry_finder[task] = entry
    heapq.heappush(pq, entry)

def remove_task(task):
    'Mark an existing task as REMOVED.  Raise KeyError if not found.'
    entry = entry_finder.pop(task)
    entry[-1] = REMOVED

def pop_task():
    'Remove and return the lowest priority task. Raise KeyError if empty.'
    while pq:
        priority, count, task = heapq.heappop(pq)
        if task is not REMOVED:
            del entry_finder[task]
            return task
    raise KeyError('pop from an empty priority queue')
memory = dict()
def clear_cache():
    global memory
    memory = dict()
def cached_fn(fn, *args):
    global memory
    if args in memory:
        return memory[args]
    else:
        result = fn(*args)
        memory[args] = result
        return result

def ncr (n,r):
    return math.factorial(n)/(math.factorial(n-r)*math.factorial(r))
def binary_serach(i,li):
    #print("Search for ",i)
    fn = lambda x: li[x]-x//i
    x = -1
    b = len(li)
    while b>=1:
        #print(b,x)
        while b+x<len(li) and fn(b+x)>0: #Change this condition 2 to whatever you like
            x+=b
        b=b//2
    return x

# -------------------------------------------------------------- MAIN PROGRAM
TestCases = True
testingMode = False
fac_warmup_size = 10**5+100
optimiseForReccursion = False #Can not be used clubbed with TestCases # WHen using recursive functions, use Python 3
from math import factorial

def main():
    b, w = get_tuple()
    maxi,mini = max(b,w), min(b,w)
    points = []
    if maxi<=mini*3 + 1:
        print("YES")
        if w>b:
            z = 0
        else:
            z = 1
        for i in range(2*mini):
            points.append([2+i+z,2])
        rem = maxi-mini
        if rem!=0:
            points.append([3+z+i,2])
        rem-=1
        for j in range(3+z, 3+i+z+1, 2):
            if rem>0:
                points.append([j,1])
                rem-=1
            if rem>0:
                points.append([j,3])
                rem-=1
        for i in points:
            display_list(i)
    else:
        print("NO")







# --------------------------------------------------------------------- END=


if TestCases: 
    for i in range(get_int()): 
        cProfile.run('main()') if testingMode else main() 
else: (cProfile.run('main()') if testingMode else main()) if not optimiseForReccursion else threading.Thread(target=main).start()