a = input()
def valid(s, x, y):
    try:
        s.index(x)
        s = s.replace(x, "*", 1)
        s.index(y)
        s = s.replace(y, "*", 1)
        return True
    except:
        return False
print(("NO", "YES")[valid(a, "AB", "BA") or valid(a, "BA", "AB")])
