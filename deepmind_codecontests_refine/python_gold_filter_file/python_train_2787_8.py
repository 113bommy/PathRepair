#頭おかしくなりそうｗ
#大体考え方は合ってるはずだけどクラス分けするのめんどくさい
D = int(input())
c = list(map(int, input().split()))
s = [list(map(int, input().split())) for _ in range(D)]
t = [int(input()) for _ in range(D)]
M = int(input())
d = []
q = []
for i in range(M):
    a, b = map(int, input().split())
    d.append(a)
    q.append(b)

    
now = 1
score = 0

decrease = 0


for i,z in enumerate(t):
    score += s[i][z - 1]

def change():
    ret = 0
    contest = [0] * 26
    date = [D * (1 + D) // 2] * 26
    for i, z in enumerate(t):
        date[z - 1] -= (D - i) * (i -contest[z-1]+ 1)
        contest[z - 1] = i + 1
    for i, z in enumerate(date):
        ret += c[i] * z
    return ret


for i, z in zip(d, q):
    score -= s[i - 1][t[i - 1] - 1]
    score += s[i - 1][z - 1]
    t[i - 1] = z
    decrease = change()
    print(score-decrease)