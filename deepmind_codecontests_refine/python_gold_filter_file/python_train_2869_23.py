n = int(input())
arr = []
for i in range(0,n):
    w = input()
    if len(w) <= 10:
        arr.append(w)
    else:
        arr.append(w[0]+str(len(w)-2)+w[-1])

for word in arr:
    print(word)