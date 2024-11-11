n,k = map(int,input().split())
answers = input().split()

names = []
army = []

for i in range(26):
    names.append('Aa'+chr(ord('a')+i))


for i in range(24):
    names.append('Ab'+chr(ord('a')+i))


for i in range(n-k+1):
    if answers[i] == 'NO':
        names[i+k-1] = names[i]

names = names[:n]
print(' '.join(names))