def f(l):
    n  = len(l)
    cl = [0]*1001
    for i in l:
        cl[i] += 1
    return max(cl) <= (n+1)//2
 
q = int(input())
l = list(map(int,input().split()))
print('YES' if f(l) else 'NO')