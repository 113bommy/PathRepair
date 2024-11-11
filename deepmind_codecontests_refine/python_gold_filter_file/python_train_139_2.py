n = int(input())
home_colors = []
guest_colors = []
for i in range(0,n):
    [h,a] = map(int, input().split())
    home_colors.append(h)
    guest_colors.append(a)
ans = 0
for i in range(0,n):
    for j in range(0,n):
        # Team i hosts team j
        if i != j and home_colors[i] == guest_colors[j]:
            ans += 1
print(ans)
        