import copy

n = int(input())
s = input()
deeps = copy.deepcopy(s)

while s.count("()") >= 1:
    s = s.replace("()","")

ans = s.count(')')* '(' + deeps + s.count('(')*')'

print(ans)