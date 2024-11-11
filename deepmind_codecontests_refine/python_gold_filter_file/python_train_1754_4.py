N,A,B,C,D = map(int, input().split())

ans = "NO"
B -= A
for i in range(N):
    num = i*D - (N-1-i)*D
    if num-i*(D-C) <= B <= num+(N-i-1)*(D-C):
        ans = "YES"
        break

print(ans)