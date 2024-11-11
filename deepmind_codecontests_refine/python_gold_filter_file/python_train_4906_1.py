import math
# from sortedcontainers import SortedList
n=int(input())
a=list(map(int,input().split()))
one_deg=[]
atleast_two=[]
sorted_deg=[]
for i in range(len(a)):
    if a[i]==1:one_deg.append(i)
    else:
        atleast_two.append(i)
        sorted_deg.append([a[i]-2,i])
if len(one_deg)>=1:
    sorted_deg.append([0,one_deg[0]])
if len(one_deg)>=2:
    sorted_deg.append([0,one_deg[1]])

sorted_deg.sort(reverse=True)
k=0
edges=[]
for i in range(len(atleast_two)-1):
    edges.append([atleast_two[i],atleast_two[i+1]])
if len(atleast_two):
    if len(one_deg)>=1:
        edges.append([one_deg[0],atleast_two[0]])
        k+=1
    if len(one_deg)>=2:
        edges.append([one_deg[1],atleast_two[-1]])
        k+=1

for [a,b] in sorted_deg:
    for j in range(a):
        if k<len(one_deg):
            edges.append([b,one_deg[k]])
            k+=1
    if k==len(one_deg):break




if k==len(one_deg):
    print("YES",len(sorted_deg)-1)
    print(len(edges))
    for [a,b] in edges:
        print(a+1,b+1)     
else :print("NO")   
    




















   