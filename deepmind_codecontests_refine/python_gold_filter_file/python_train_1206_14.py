def contains(s, frm, p, pos):
    if pos == len(p):
        return True
    ind = s.find(p[pos], frm)    
    if ind < 0:
        return False
    else:
        return contains(s, ind + 1, p, pos + 1)

print(('NO', 'YES')[contains(input(), 0, 'heidi', 0)])
