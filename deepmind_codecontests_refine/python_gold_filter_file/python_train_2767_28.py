def Main():
  n = int(input())
  x = int(input())
  arr = [[1,2,3],[2,1,3],[2,3,1],[3,2,1],[3,1,2],[1,3,2]]
  print(arr[n%6][x] - 1)
  
if __name__ == '__main__':
  Main()