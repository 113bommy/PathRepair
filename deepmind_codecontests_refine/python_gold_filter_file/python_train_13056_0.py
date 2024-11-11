class Scroll:
	def __init__(self, id, power, damage):
		self.id = id
		self.power = power
		self.damage = damage
		self.active = False

num_scrolls, boss_max, regenerate = map(int, input().split())
scrolls = [Scroll(i+1, *map(int, input().split())) for i in range(num_scrolls)]
scrolls.sort(key = lambda scroll: -scroll.damage)
boss_curr = boss_max
scroll_damage = 0
active_scrolls = []
tick = 0
while True:
	boss_prev = boss_curr
	boss_curr -= scroll_damage
	boss_curr = min(boss_max, boss_curr + regenerate)
	if boss_curr <= 0:
		print('YES')
		print(tick, len(active_scrolls))
		for scroll in active_scrolls:
			print(scroll.start, scroll.id)
		break
	found = False
	for scroll in scrolls:
		if not scroll.active and 100*boss_curr <= scroll.power*boss_max:
			scroll.start = tick
			scroll.active = True
			active_scrolls.append(scroll)
			scroll_damage += scroll.damage
			found = True
			break
	if not found and boss_curr >= boss_prev:
		print('NO')
		break
	tick += 1
