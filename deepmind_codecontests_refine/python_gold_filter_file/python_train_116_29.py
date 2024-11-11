_ = input()
x = input()
start = 0
for i,ch in enumerate(x):
    if i == 0: continue
    if x[start] > ch:
        print("YES")
        print(start+1, i+1)
        break
    if ch > x[start]: start = i
else:
    print("NO")
