x, y = input().split()
x = int(x)
y = int(y)
st1 = []
st2 = []
for i in range(y):
    s1, s2 = input().split()
    st1.append(s1)
    st2.append(s2)
sr = input()
words = [str(w) for w in sr.split()]
for word in words:
    i = st1.index(word)
    if len(st1[i]) <= len(st2[i]):
        print(st1[i], end=' ')
    else:
        print(st2[i], end=' ')

