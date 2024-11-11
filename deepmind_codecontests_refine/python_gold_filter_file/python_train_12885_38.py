S,T = input(), input()

print(len(list(filter(lambda i : S[i] != T[i], range(len(S))))))
