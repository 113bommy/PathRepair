import sys
input = sys.stdin.readline
s = input()
# p = []
n = len(s)-1
for i in range(n):
    if i == 0:
        sys.stdout.write("Mike"+"\n")
        x = s[i]
        continue

    if x < s[i]:
        sys.stdout.write("Ann" + "\n")
        continue

    else:
        sys.stdout.write("Mike" + "\n")

    x = min(x,s[i])