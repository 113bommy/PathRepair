S = input()
print('Good' if all(S[i+1]!=S[i] for i in range(3)) else 'Bad')