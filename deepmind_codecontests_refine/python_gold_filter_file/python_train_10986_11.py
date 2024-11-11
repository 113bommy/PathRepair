n = int(input())
heights = list(map(int, input().split()))
 
if n == 1:
    print(1)
else:
    max_val = 0
    for i in range(n):
        current = 0
        for j in range(i - 1, -1, -1):
            if heights[j] > heights[j + 1]:
                break
            current += 1
            
        for j in range(i + 1, n):
            if heights[j] > heights[j - 1]:
                break
            current += 1

        max_val = max(max_val, current)

    print(max_val + 1)