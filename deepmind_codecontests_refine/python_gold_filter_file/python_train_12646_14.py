alf = "abcdefghijklmnopqrstuvwxyz"
n = int(input())
string = input().lower()
w = set()
for i in string:
    if string.count(i) >= 1:
        w.add(i)
if len(w) >= len(alf):
    print("YES")
else:
    print("NO")
