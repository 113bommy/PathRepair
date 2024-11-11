from sys import stdin,stdout
import itertools

count=0
n = int(input())
l1 = sorted(list(map(int,stdin.readline().rstrip().split(' '))))
l2 = sorted(list(map(int,stdin.readline().rstrip().split(' '))))
if(l1[n-1] in l2):
    for i,j in zip(l1,l2):
        if(i!=j):
            print(i)
            break
        else:
            count+=1
            if(count==n-1):
                print(l1[n-1])
else:
    print(l1[n-1])
l3 = sorted(list(map(int,stdin.readline().rstrip().split(' '))))

count=0

if(l2[n-2] in l3):
    for i,j in zip(l2,l3):
        if(i!=j):
            print(i)
            break
        else:
            count+=1
            if(count==n-2):
                print(l2[n-2])

else:
    print(l2[n-2])