
from collections import Counter

def pro(arr):
    dic=Counter(arr)
    lst=[]
    for i,j in dic.items():
        lst.append((i,j))
    lst=sorted(lst,key=lambda x:(-x[1],x[0]))
    #print(lst)
    print(len(arr)-lst[0][1])

n=int(input())
arr=list(map(int,input().split()))
pro(arr)