n = int(input())
arr = list(map(int, input().split()))
ans = []
for i in range(n):
    higher = 0
    for j in range(n):
        if(i != j and arr[j] > arr[i]):
            higher += 1
    ans.append(str(higher + 1))
print(" ".join(ans))
