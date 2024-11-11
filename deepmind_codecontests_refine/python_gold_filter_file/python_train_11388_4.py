# http://codeforces.com/problemset/problem/296/A
input()
get=lambda:list(map(int,input().split()))
l=get()
if len(l)==1:
    
    print("YES")
    exit()
from collections import Counter
c=Counter(l)
s=c.most_common(1)[0][1]
if s-1<=len(l) -s:
    print("YES")
else:
    print("NO")
