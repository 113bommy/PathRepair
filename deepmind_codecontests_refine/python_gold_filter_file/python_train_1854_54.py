S = input()
A = 'Good'
for i in range(3):
    if S[i] == S[i+1]:
        A = 'Bad'

print(A)