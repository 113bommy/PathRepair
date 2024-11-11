def mp():  return map(int,input().split())
def lt():  return list(map(int,input().split()))
def pt(x):  print(x)
def ip():  return input()
def it():  return int(input())
def sl(x):  return [t for t in x]
def spl(x): return x.split()
def aj(liste, item): liste.append(item)
def bin(x):  return "{0:b}".format(x)
def printlist(l): print(' '.join([str(x) for x in l]))
def listring(l): return ''.join([str(x) for x in l])

n,a,b = mp()
if n > a*b:
    print(-1)
    exit()
G = [[0 for j in range(b)] for i in range(a)]
if b % 2 == 0:
    for i in range(n):
        r,s = i//b, i%b
        if r % 2 == 0:
            G[r][s] = i+1
        else:
            G[r][b-1-s] = i+1
else:
    for i in range(n):
        r,s = i//b, i%b
        G[r][s] = i+1
for i in range(a):
    printlist(G[i])
        

        