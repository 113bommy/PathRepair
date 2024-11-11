import sys
def input():    return sys.stdin.readline().strip()
def iinput():   return int(input())
def minput():   return map(int, input().split()) 
def listinput(): return list(map(int, input().split()))
for _ in range(iinput()):
    n=iinput()
    p=listinput()
    even_p,odd_p=0,0
    for i in p:
        if i%2==0:
            even_p+=1
        else:
            odd_p+=1
    m=iinput()
    q=listinput()
    even_q,odd_q=0,0
    for i in q:
        if i%2==0:
            even_q+=1
        else:
            odd_q+=1
    print(even_p*even_q+odd_p*odd_q)