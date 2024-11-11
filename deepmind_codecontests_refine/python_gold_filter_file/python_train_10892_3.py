n, s = int(input()), input()
print(2 * (min(s.count('U'), s.count('D')) + min(s.count('L'), s.count('R'))))