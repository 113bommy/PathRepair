K=int(input())
R=K%50
L=K//50
a = [49 - R + L for i in range(50)]
for i in range(R):
    a[i] += 51
print(50)
print(' '.join(map(str, a)))