user_input = str(input())
if len(user_input) == 3:
  M = int(user_input[0])
  N = int(user_input[2])
elif len(user_input) == 4:
  M = int(user_input[0])
  N = int(user_input[2 : 4])
else:
  M = int(user_input[0 : 2])
  N = int(user_input[3 : 5])
if M >= 1 and N <= 16 and N >= M:
  answer = (M * N) // 2
  print(answer)