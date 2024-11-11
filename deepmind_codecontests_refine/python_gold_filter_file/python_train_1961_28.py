N = input()
l = len(N)-1
print(N if l == 0 else int(N[0]) + 9*l if N[1:] == '9'*l else int(N[0]) - 1 + 9*l)