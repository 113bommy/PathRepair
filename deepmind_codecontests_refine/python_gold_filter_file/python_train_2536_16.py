s = input()
pl, rui = 4 if s[0] == 'h' else 3, s.rfind('ru')
print(s[:pl] + '://' + s[pl:rui] + '.ru' + ('/' + s[rui + 2:] if rui < len(s) - 2 else ''))
