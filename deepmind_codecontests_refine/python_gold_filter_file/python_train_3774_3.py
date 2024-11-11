# Why do we fall ? So we can learn to pick ourselves up.

alpha = "abcdefghijklmnopqrstuvwxyz"
t = int(input())
for _ in range(0,t):
    n,m = map(int,input().split())
    aa = []
    for _ in range(0,n):
        s = input()
        aa.append(s)
    ok = False
    for i in range(0,m):
        for j in alpha:
            ans = list(aa[0])
            ans[i] = j
            ok = True
            for ii in range(0,n):
                diff = 0
                for jj in range(0,m):
                    if ans[jj] != aa[ii][jj]:
                        diff += 1
                if diff > 1:
                    ok = False
                    break
            if ok:
                break
        if ok:
            break
    if ok:
        print("".join(ans))
    else:
        print(-1)




"""
5
2 4
abac
zbab
2 4
aaaa
bbbb
3 3
baa
aaa
aab
2 2
ab
bb
3 1
a
b
c




"""