from collections import deque


class ColorStore:

	def __init__(self):
		self.colors = deque(["R", "O", "Y", "G", "B", "I", "V"])

	def get(self):
		color = self.colors.popleft()
		self.colors.append(color)
		return color	
 

def solution(n):
	result = [None] * n
	_len = len(result)
	cs = ColorStore()

	for i in range(n):
		color = cs.get()
		
		_len_tail = len(result[i:])
		if _len_tail < 4:
			tail = result[i:] + result[0:4-_len_tail]
			while color in tail:
				color = cs.get()
			
		result[i] = color

	return "".join(result)
		
	

if __name__ == "__main__":
	n = int(input())
	print(solution(n))


