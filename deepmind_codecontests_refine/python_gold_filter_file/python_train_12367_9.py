import sys,collections as cl,bisect as bs
sys.setrecursionlimit(100000)
mod = 10**9+7
Max = sys.maxsize
def l(): #intのlist
    return list(map(int,input().split()))
def m(): #複数文字
    return map(int,input().split())
def onem(): #Nとかの取得
    return int(input())
def s(x): #圧縮
    a = []
    aa = x[0]
    su = 1
    for i in range(len(x)-1):
        if aa != x[i+1]:
            a.append([aa,su])
            aa = x[i+1]
            su = 1
        else:
            su += 1
    a.append([aa,su])
    return a
def jo(x): #listをスペースごとに分ける
    return " ".join(map(str,x))
def max2(x): #他のときもどうように作成可能
    return max(map(max,x))
def In(x,a): #aがリスト(sorted)
    k = bs.bisect_left(a,x)
    if k != len(a) and a[k] ==  x:
        return True
    else:
        return False
"""
def nibu(x,n,r):
    ll = 0
    rr = r
    while True:
        mid = (ll+rr)//2

    if rr == mid:
        return ll
    if (ここに評価入れる):
        rr = mid
    else:
        ll = mid+1
"""



n = onem()
A = l()
B = l()

def count(start,id):
    co = 0
    s = start

    while True:
        s = id[s]
        co += 1
        if s == 0:
            break
    return co

L = []

for i in range(n):
    L.append([A[i],B[i]])
L.sort(key=lambda x:x[1])
p = sorted(range(n) , key = lambda i:L[i][0])

A.sort()



bo1 = all(A[i] <= L[i][1] for i in range(n))
bo2 = any(A[i+1] <= L[i][1] for i in range(n-1))
bo3 = count(0,p) <= n-2

print("Yes" if (bo1 and (bo2 or bo3)) else "No")
