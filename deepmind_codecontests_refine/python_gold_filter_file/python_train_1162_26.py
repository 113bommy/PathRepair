GI = lambda: int(input()); GIS = lambda: map(int, input().split()); LGIS = lambda: list(GIS())

CATS = 'DABC'
def main():
  x = GI()
  r = (x % 4)
  res = [
    '1 A',
    '0 A',
    '1 B',
    '2 A',
  ][r]
  print(res)

main()
