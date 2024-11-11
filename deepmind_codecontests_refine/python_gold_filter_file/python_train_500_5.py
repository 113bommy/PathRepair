S = input()
c = [0, 0, 0]
for i in S:
    c[ord(i) - ord('a')] += 1
for i in c:
    if i > (len(S) + 2) // 3:
        print("NO")
        break
else:
    print("YES")