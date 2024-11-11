import sys
input = sys.stdin.readline

n,m=map(int,input().split())

x=(n-3)//2
MAX=x*(x+1)

if n%2==1:
    MAX+=(n-1)//2
else:
    MAX+=(n-1)//2*2

#print(MAX)

if m>MAX:
    print(-1)
    sys.exit()

score=0
x=1
while score<m:
    x+=1
    score+=(x-1)//2

#print(x,score)

LAST1=x
x+=(score-m)*2

ANS=list(range(1,LAST1))
ANS.append(x)

for i in range(n-len(ANS)):
    ANS.append(10**9-i*5001-1)

print(*sorted(ANS))
