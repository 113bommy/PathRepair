def check(a,b,n,m):
        for i in range(1,n+1):
                if (i not in a):
                        return False
        for i in range(1,m+1):
                if (i not in b):
                        return False
        return True

from math import *
T = int(input())
for _ in range(T):
        n = int(input())
        arr = list(map(int,input().split()))
        Arr = [0]*max(arr)
        for i in arr:
                Arr[i-1] += 1
        flag = 0
        for i in range(1,len(Arr)):
                if (Arr[i]>Arr[i-1]):
                        flag = 1
                        break
                if (Arr[i]==0 or Arr[i-1]==0):
                        flag = 1
                        break
        Max = max(Arr)
        Min = min(Arr)
        if (flag==0 and Max==2):
                a = max(arr)
                b = n-a
                Dict1 = {arr[i]:1 for i in range(a)}
                Dict2 = {arr[i]:1 for i in range(a,n)}
                Dict3 = {arr[i]:1 for i in range(b)}
                Dict4 = {arr[i]:1 for i in range(b,n)}
                A = check(Dict1,Dict2,a,b)
                B = check(Dict3,Dict4,b,a)
                if (A==True and B==True and a!=b):
                        print(2)
                        print(a,b)
                        print(b,a)
                elif(A==True):
                        print(1)
                        print(a,b)
                elif(B==True):
                        print(1)
                        print(b,a)
                else:
                        print(0)
        else:
                print(0)
                

        