def solve():
    S = input()
    n = len(S)
    if S[0]==S[1]:
        return [1,2]
    for i in range(1,n):
        if S[i]==S[i-1]:
            return [i,i+1]
        if i>=2 and S[i]==S[i-2]:
            return [i-1,i+1]
    return [-1,-1]
print(*solve())