n,k = [int(x) for x in input().split()]
piles = [int(x) for x in input().split()]

min_val = min(piles)
max_val = max(piles)

if max_val - min_val > k:
    print("NO")
    quit()
else:
    print("YES")
    for i in range(n):
        line = "1"
        for j in range(2,piles[i]+1):
            if j<= min_val:
                line += " 1"
            else:
                line += " " + str(j-(min_val))
        print(line)