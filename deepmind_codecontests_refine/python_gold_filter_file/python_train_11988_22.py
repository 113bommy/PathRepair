def kanban(x):
    if x == 12:
        return False 
    if x >= 10 and x < 30:
        return True
    if x >= 70 and x < 80:
        return True
    if x >= 90:
        return True
    return (x % 10) in [1, 7, 9]

print('NO' if kanban(int(input())) else 'YES')