a = input()
n = len(a)
ansa = -1
ansb = -1
for i in range(n-1):
    if a[i] ==a[i+1]:
        ansa = i
for j in range(n-2):
    if a[j] ==a[j+2]:
        ansb = j
if ansa != -1:
    print(ansa+1,ansa+2)
elif ansb != -1:
    print(ansb+1,ansb+3)
else:
    print(-1,-1)