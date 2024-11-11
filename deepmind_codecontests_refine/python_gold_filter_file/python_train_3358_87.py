n = int(input())
lengs = []
for i in range(n):
    lengs.append(int(input()))

masses = []
for leng in lengs:
    masses.append([])
    app = 1000
    for i in range (leng):
        masses[len(masses) - 1].append(str(1000))
        app -= 1

for i in range(len(masses)):
    st = ' '.join(masses[i])
    print(st)
