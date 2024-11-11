def kmp(txt,pat):
    N = len(txt)
    M = len(pat)
    i = 0
    j = 0
    cnt = 0
    lps = [0]*M
    computeLps(pat,lps,M)

    while i < N:
        if txt[i] == pat[j]:
            i +=1
            j +=1
        if j == M:
            cnt +=1
            j = lps[j-1]
        elif i < N and txt[i] != pat[j]:
            if j != 0:
                j = lps[j-1]
            else:
                i +=1
    return cnt



    

def computeLps(pat,lps,M):
    len = 0
    i = 1

    while i<M:
        if pat[i] == pat[len]:
            len +=1
            lps[i] = len
            i +=1
        else:
            if len !=0:
                len = lps[len-1]
            else:
                lps[i] = 0
                i +=1


def computeDiff(a,n):

    rs = [0]*(n-1)
    for i in range(1,n):
        rs[i-1] = a[i] - a[i-1]
    return rs




n,m = map(int, input().split())
if n == 1 or m == 1:
    print(n)
    exit(0)
a = list(map(int,input().split()))
b = list(map(int,input().split()))
new_a = computeDiff(a,n)
new_b = computeDiff(b,m)
print(kmp(new_a, new_b))