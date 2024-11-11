s = input()
s = s.replace("BC","X")
ans = []
c = 0

for i in range(1,len(s)+1):
    if s[-1 * i] == "X":
        c += 1
    elif s[-1 * i] == "A":
        ans.append(c)
    else:
        c = 0
print(sum(ans))
