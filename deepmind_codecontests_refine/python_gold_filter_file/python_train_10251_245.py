def solve(n):
    if(n%2==0):
        return n//2
    else:
        prev = (n-1)//2
        return prev-n



n = int(input())
print(solve(n))