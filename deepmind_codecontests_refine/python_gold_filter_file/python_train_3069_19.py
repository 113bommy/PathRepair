t = 8
score_b = {"p": 1, "n": 3, "b": 3, "r": 5, "q": 9}
score_w = {"P": 1, "N": 3, "B": 3, "R": 5, "Q": 9}
lines = ""
while t:
    lines += input()
    t = t - 1
t_b = 0
t_w = 0
for j, k in score_b.items():
    c = lines.count(j)
    t_b += c * k

for j, k in score_w.items():
    c = lines.count(j)
    t_w += c * k

if t_b > t_w:
    print("Black")
elif t_b < t_w:
    print("White")
else:
    print("Draw")