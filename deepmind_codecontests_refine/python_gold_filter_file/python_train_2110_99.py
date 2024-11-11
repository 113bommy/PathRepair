def resolve():
  N = int(input())

  for _ in range(N):
    inputed_number = int(input())
    result = []
    for i in reversed(range(1, inputed_number+1)):
      result.append(str(i))
    
    print(" ".join(result))

if __name__ == "__main__":
  resolve()