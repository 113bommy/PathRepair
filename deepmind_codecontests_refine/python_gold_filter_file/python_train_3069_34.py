from collections import Counter

b = w = 0
a = []
for i in range(8):
    a.extend(' '.join(input()).split())
c = Counter(a)
w += c['Q'] * 9
w += c['R'] * 5
w += c['B'] * 3
w += c['N'] * 3
w += c['P'] * 1
b += c['q'] * 9
b += c['r'] * 5
b += c['b'] * 3
b += c['n'] * 3
b += c['p'] * 1
print('White' if w > b else 'Draw' if w == b else 'Black')
