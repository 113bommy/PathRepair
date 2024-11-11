#%%
import sys, os, math

# sys.stdin = open(os.getcwd()+'\input.txt', 'r')  

t = int(sys.stdin.readline())
for i in range(0,t):
    n = str(sys.stdin.readline())
    arr = [int(x) for x in sys.stdin.readline().split()]
    C_A = []
    if len(arr) <= 3:
        print(arr[0])
    elif len(arr) == 4:
        print(arr[0] + min(arr[1:]))
    else: 
        C_A.append(arr[-1])
        C_A.append(arr[-2])
        C_A.append(arr[-3])
        C_A.append(arr[-4] + min(arr[-1], arr[-2], arr[-3]))
        for i in range(4,len(arr)):
            a = arr[-(i+1)] + C_A[(i-2)]
            b = arr[-(i+1)] + C_A[(i-3)]
            c = arr[-(i+1)] + arr[-(i)] + C_A[(i-3)]
            d = arr[-(i+1)] + arr[-(i)] + C_A[(i-4)]
            C_A.append(min(a,b,c,d))
        ans = C_A[-1]
        print(ans)







# %%
