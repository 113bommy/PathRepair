
##########################################################
from collections import Counter
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
import heapq
# c=sorted((i,int(val))for i,val in enumerate(input().split()))
# n = int(input())
# ls = list(map(int, input().split()))
# n, k = map(int, input().split())
# n =int(input())
# e=list(map(int, input().split()))
from collections import Counter
#print("\n".join(ls))
#print(os.path.commonprefix(ls[0:2]))
#for i in range(int(input())):
#n=int(input())

n=int(input())
ls=[]
ans=0
for  i in range(3):
    s=input()
    c = Counter(s)
    if all(i==s[0] for i in s) and n==1:
        ls.append(len(s)-1)
    else:
        ls.append(min(max(c.values())+n,len(s)))
cc=ls.count(max(ls))
if cc>=2:
    print("Draw")
else:
    if ls.index(max(ls))==0:
        print("Kuro")
    elif ls.index(max(ls))==1:
        print("Shiro")
    else:
        print("Katie")




