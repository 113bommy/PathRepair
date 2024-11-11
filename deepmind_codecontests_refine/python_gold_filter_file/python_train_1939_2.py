N = int(input())
w = list(map(int, input().split()))
w.sort()
ans = float('inf')
for i in range(len(w)):
    for j in range(i + 1, len(w)):
        new_w = []
        for k in range(len(w)):
            if k != i and k != j:
                new_w.append(w[k])
        
        total_instability = 0
        for k in range(0, len(new_w), 2):
            total_instability += new_w[k + 1] - new_w[k]
        ans = min(total_instability, ans)

print(ans)
        




        


    
    