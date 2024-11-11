t = int(input())
n=[]
for i in range(t):
    num=int(input())
    n.append(num)

count=0
def powin(num,k):
    global count
    if num%k==0:
        num=int(num/k)
        count+=1
        powin(num,k)
    return count

for i in range(t):
    count=0
    p2=powin(n[i],2)
    count=0
    p3=powin(n[i],3)
    if n[i]==1:
        print(0)
    elif n[i]/((2**p2)*(3**p3))==1 and p2<=p3:
        print(2*p3-p2)
    else:
        print(-1)