n  = int(input())
ss = []
for i in range(n):
    s = input()
    if s[-2:] == "po":
        print()
        ss.append("FILIPINO")
    if s[-4:] == "desu" or s[-4:] == "masu":
        ss.append("JAPANESE")
    if s[-5:] == "mnida":
        ss.append("KOREAN")

for i in ss:
    print(i)