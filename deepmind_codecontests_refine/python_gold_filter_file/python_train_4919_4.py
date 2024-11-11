N,S = map(int, input().split(" "))
max_val = S - N + 1
if (max_val <= (S+1)/2):
    print("NO")
else:
    print("YES")
    for i in range(N - 1):
        print(1, end=" ")
    print(max_val)
    print(max_val - 1)

