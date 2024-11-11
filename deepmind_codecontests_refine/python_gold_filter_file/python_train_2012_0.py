#######puzzleVerma#######


import sys
import math
from typing import DefaultDict
mod = 10**9+7
from bisect import *


LI=lambda:[int(k) for k in input().split()]
input = lambda: sys.stdin.readline().rstrip()
IN=lambda:int(input())
S=lambda:input()
r=range


for t in r(IN()):
    n=IN()
    li=LI()
    ss=set(li)
    sli=sorted(li)
    d=DefaultDict(int)
    d2=DefaultDict(int)
    for i in range(n):
        if i%2:
            d[li[i]]+=1
        else:
            d2[li[i]]+=1
    for i in range(n):
        if i%2:
            d[sli[i]]-=1
        else:
            d2[sli[i]]-=1
    for ele in ss:
        if (d[ele]!=0 or d2[ele]!=0):
            print("NO")
            break
    else:
        print("YES")

    # tb=[True]*n
    # i=0
    # j=0
    # ans=True
    # while i<n:
    #     j=i
    #     while (li[j]!=sli[i]):
    #         j+=1
    #     while (i<j):
    #         tb[j]=not tb[j]
    #         tb[j-1]=not tb[j-1]
    #         li[j],li[j-1]=li[j-1],li[j]
    #         tb[j],tb[j-1]=tb[j-1],tb[j]
    #         j-=1
    #     i+=1
    # for i in range(n):
    #     ans=(ans and tb[i])
    # if ans:
    #     print("YES")
    # else:
    #     print("NO")


# for t in r(IN()):
#     n=IN()
#     li=LI()
#     sli=sorted(li)
#     d=DefaultDict(int)
#     tb=[True]*n
#     flag=0
#     for i in range(n):
#         j=bisect(sli,li[i])-1
#         if ((j-i)%2==0 and d[j]==0):
#             d[j]=1
#             while (i<j):
#                 li[j],li[j-1]=li[j-1],li[j]
#                 bl=tb[j]
#                 tb[j]=not tb[j-1]
#                 j-=1
#             tb[i]=bl
#         elif (j>0 and (j-1-i)%2==0 and d[j-1]==0 and sli[j-1]==li[i]):
#             d[j-1]=1
#             j-=1
#             while (i<j):
#                 li[j],li[j-1]=li[j-1],li[j]
#                 bl=tb[j]
#                 tb[j]=not tb[j-1]
#                 j-=1
#             tb[i]=bl
#         else:
#             flag=1
#             break
#         print(tb)
#     ans=True
#     for i in range(n):
#         ans=(ans and tb[i])
#     if flag==0 and ans:
#         print("YES")
#     else:
#         print("NO")






    # i=0
    # j=0
    # swap=0
    # flag=1
    # tb=[True]*n
    # while i<n:
    #     j=i
    #     swap=0
    #     while li[j]!=sli[i] and ((swap%2==0 and tb[j]) or (swap%2 and not tb[j])):
    #         j+=1
    #         if j==n:
    #             flag=1
    #             break
        
    #     if flag==1:
    #         break
        
    #     while (i<j):
    #         tb[j-1]=not tb[j-1]
    #         li[j],li[j-1]=li[j-1],li[j]
    #         j-=1
    #     i+=1
    # if flag==1:
    #     print("NO")
    #     continue
    # ans=True
    # for i in range(n):
    #     ans=(ans and tb[i])
    # if ans:
    #     print("YES")
    # else:
    #     print("NO")


