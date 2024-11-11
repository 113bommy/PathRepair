
n = int(input())
datos = input().split()
formas_original = []
for num in datos:
    formas_original.append(int(num))    
formas = formas_original

hay = False

i = 0
while i<n and not hay:
    j = 0
    while j<n and not hay:
        k = 0
        while k<n and not hay:
            if i != j and j != k:
                if formas[i] + formas[j] == formas[k]:
                    print(k+1,j+1,i+1)
                    hay = True
            k = k+1
        j = j+1
    i = i+1
if not hay:
    print(-1)