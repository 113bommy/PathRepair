from sys import stdin,stdout
from collections import defaultdict
input=lambda:stdin.readline().strip()
for _ in range(int(input())):
    s1=input()
    s2=input()
    n1=len(s1)
    n2=len(s2)
    lst1=[0]*26
    nk=0
    for i in s1:
        lst1[ord(i)-97]+=1
    for i in range(0,n2):
        lst2=[0]*26
        for j in range(i,n2):
            lst2[ord(s2[j])-97]+=1
            if lst2==lst1:
                print('YES')
                nk=1
                break
        if nk==1:
            break
    if nk==0:
        print('NO')
